import sqlite3
from threading import Lock

class DBHandler():
    def __init__(self, dbpath,tag_names,tablename='dataTable'):
        """
        Classe para manipulação do banco de dados
        """
        self._con = sqlite3.connect(dbpath, check_same_thread=False)
        self._cursor = self._con.cursor()
        self._lock = Lock()
        self._tablename = tablename
        self.create_table(tablename,tag_names)
        
    def __del__(self):
        """
        Destrutor da classe BDHandler 
        """
        self._con.close()
    
    def create_table(self,tablename,tag_names):   
        """
        Método que cria a tabela para armazenamento dos dados caso ela
        não exista no arquivo
        """
        try:
            sql_real_cols = ' REAL,'.join(tag_names)
            sql_str = f"""
            CREATE TABLE IF NOT EXISTS {tablename}(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 
            timestamp TEXT NOT NULL, {sql_real_cols} REAL);
            """
            self._lock.acquire()
            self._cursor.execute(sql_str)
            self._con.commit()
            self._lock.release()
        except Exception as e:
            print("Erro na criação da tabela: ", e.args)

    def insert_data(self, data): 
        """
        Método para inserção dos dados no BD
        """    
        try:
            data['timestamp'] = f"'{data['timestamp']}'"
            str_cols = ','.join(data.keys())
            str_values = ','.join([str(data[tag]) for tag in data.keys()])
            sql_str = f'INSERT INTO {self._tablename} ({str_cols}) VALUES ({str_values});'
            self._lock.acquire()
            self._cursor.execute(sql_str)
            self._con.commit()  
            self._lock.release()
        except Exception as e:
            print("Erro na inserção de dados no BD: ", e.args)    

    def select_data(self, tags, init_t, final_t):
        """
        Método para coleta de dados no BD entre 2 horários especificados
        """ 
        cols = list(tags)
        cols.insert(0,'timestamp')
        try:
            query = f"SELECT  {','.join(cols)} FROM {self._tablename} WHERE timestamp BETWEEN '{init_t}' AND '{final_t}'"  
            self._lock.acquire()
            self._cursor.execute(query)
            self._lock.release()
            selected_data = {'cols': cols, 'data':[]}
            for linha in self._cursor.fetchall():
                selected_data['data'].append(linha)
            return selected_data
        except Exception as e:
            print("Erro na busca de dados do BD: ", e.args)    