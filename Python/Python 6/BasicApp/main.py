import kivy
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.config import Config

class MyWidget(BoxLayout):
    def changelb(self):
        """
        Método simples para incremento do valor mostrado no label
        """
        self.ids['lb'].text = str(int(self.ids.lb.text) + 1) 

class BasicApp(App):
    def build(self):
        """
        Método para construção do aplicativo com base no widget criado
        """
        return MyWidget()
 
if __name__ == '__main__':
    Config.set('graphics','resizable',True)
    BasicApp().run()