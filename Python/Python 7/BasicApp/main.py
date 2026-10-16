import kivy
from kivy.app import App
from kivy.uix.floatlayout import FloatLayout
from kivy.core.window import Window

class MyWidget(FloatLayout):
    """
    Classe MyWidget - layout principal, com aparência definida em basic.kv
    """
    pass

class BasicApp(App):
    """
    Aplicativo Kivy com interface carregada de basic.kv
    """


    def build(self):
        """
        Método para construção do aplicativo com base no widget criado
        :return: widget principal da aplicação (MyWidget)
        """
        return MyWidget()
 
if __name__ == '__main__':
    Window.size=(800,600)
    Window.fullscreen = False
    BasicApp().run()