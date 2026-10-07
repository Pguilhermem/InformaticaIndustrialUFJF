from db import Base
from sqlalchemy import Column, Integer, DateTime

class DadoCLP(Base):
    """
    Modelo dos dados do CLP
    """
    __tablename__ = 'dadoclp'
    id = Column(Integer, primary_key=True)
    timestamp = Column(DateTime)
    temperatura = Column(Integer)
    pressao = Column(Integer)
    umidade = Column(Integer)
    consumo = Column(Integer)

    def get_attr_printable_list(self):
        """
        Método que devolve os valores do registro numa lista, com a data formatada para exibição
        :return: lista no formato [id, 'DD/MM/AAAA HH:MM:SS', temperatura, pressao, umidade, consumo]
        """

        return [self.id,
        self.timestamp.strftime('%d/%m/%Y %H:%M:%S'),
        self.temperatura,
        self.pressao,
        self.umidade,
        self.consumo]
