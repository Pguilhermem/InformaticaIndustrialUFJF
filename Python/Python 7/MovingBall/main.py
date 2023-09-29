from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.core.window import Window
from kivy.clock import Clock
from time import sleep

class MyWidget(BoxLayout):
    _vel = [1,1]

    def move(self,dt):
        self.ids.bola.x += self._vel[0]
        self.ids.bola.y += self._vel[1]
        if self.ids.bola.x < 0 or self.ids.bola.right > self.ids.valid_region.width:
            self._vel[0] *= -1
        if self.ids.bola.y < 0 or self.ids.bola.top > self.ids.valid_region.height:
            self._vel[1] *= -1

      
    def command(self):
        if self.ids.bt_mover.text == "Mover":
            self._ev = Clock.schedule_interval(self.move, 1.0/60.0)
            self.ids.bt_mover.text = "Parar"
        elif self.ids.bt_mover.text == "Parar":
            self._ev.cancel()
            self.ids.bt_mover.text = "Mover"

class MovingBallApp(App):
    def build(self):
        """
        Método para construção do aplicativo com base no widget criado
        """
        return MyWidget()

if __name__ == '__main__':
    Window.size = (800,600)
    Window.fullscreen = False
    MovingBallApp().run()