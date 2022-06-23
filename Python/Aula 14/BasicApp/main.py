import kivy
from kivy.app import App
from kivy.uix.floatlayout import FloatLayout
from kivy.core.window import Window

class MyWidget(FloatLayout):
    def changelb(self):
        """
        Método simples para incremento do valor mostrado no label
        """
        pass

class BasicApp(App):
    def build(self):
        """
        Método para construção do aplicativo com base no widget criado
        """
        return MyWidget()
 
if __name__ == '__main__':
    Window.size=(640,480)
    Window.fullscreen = True
    BasicApp().run()