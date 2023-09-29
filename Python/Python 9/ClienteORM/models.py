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
        return [self.id,
        self.timestamp.strftime('%d/%m/%Y %H:%M:%S'),
        self.temperatura,
        self.pressao,
        self.umidade,
        self.consumo]
