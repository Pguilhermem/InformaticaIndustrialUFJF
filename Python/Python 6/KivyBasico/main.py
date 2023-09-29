import kivy
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label

class BasicApp(App):
    """
    Aplicativo básico Kivy
    """
    def build(self):
        """
        Constrói o aplicativo a partir de um conjunto de widgets
        :return Widget principal da aplicação
        """
        layout = BoxLayout(orientation = 'horizontal')
        self.lb = Label(text="0")
        bt = Button(text = "Botão 1", on_release = self.incrementar)
        layout.add_widget(self.lb)
        layout.add_widget(bt)
        
        
        layout2 = BoxLayout(orientation = 'vertical')
        self.lb2 = Label(text="0", color=[1,0,0,1])
        self.lb3 = Label(text="0")
        layout2.add_widget(self.lb2)
        layout2.add_widget(self.lb3)
        layout.add_widget(layout2)

        return layout
    
    def incrementar(self,*args):
        self.lb.text = str(int(self.lb.text)+1) 
        self.lb2.text = str(int(self.lb2.text)+2) 
        self.lb3.text = str(int(self.lb3.text)+3) 

if __name__=='__main__':
    BasicApp().run()
