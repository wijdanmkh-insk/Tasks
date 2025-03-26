import custom
from PIL import Image 

window = ctk.CTk()
window.geometry("800x600") #ukuran window
window.title("Login Page")
window.resizable(0,0)

background = ctk.CTkLabel(
    root, 
    image=ctk.CTkImage(Image.open('page.png')) size("800,600")#Buat nama gambar
    text = ''
)
background.pack()

button=ctk.CTkButton(
    text
)

background.pack(expand=True)

loginframe = ctk.CTkFrame(
    background, 
    width=400
    height=400
)

passwordform = ctk.CTkEntry(
    loginframe, 
    text=''
)
loginframe = ctk.CTk
button.pack()
window.mainloop()