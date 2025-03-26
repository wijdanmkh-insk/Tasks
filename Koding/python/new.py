#a = (input()) #fungsi eval hanya bisa dilakukan untuk satu variabel saja dan menggabungkan variabel satu dengan lainnya
#c = eval(a) #hanya bisa string yang diambil
#print(c) #fungsi eval dapat diisi dengan simbol operasi hitung lainnya

#a = int(input())
#sign = input()
#b = int(input())

#def penjumlahan(a,b):
#    return a+b
#def pengurangan(a,b):
#    return a-b
#def perkalian(a,b):
#    return a*b
#def pembagian(a,b):
#    return a/b 

#def operate(a, b, sign):
#    if sign == "+" :
#    print(a+b)
#    elif sign == "-" :
#    c=a-b
#    elif sign == "*" :
#    c = a * b
#    elif sign == "/" :
#    c = a / b

#    return c

#a, b = int(input()).split()
#sign = input()

#a = []
#for i in range(2):
#    angka = int(input("Masukkan angka {} : ", i+1))
#    a.append(angka)
#print(angka)

def penjumlahan(a):
    var = 0
    var = var + a

def pengurangan(a):
    var = 0
    var = var - a

def perkalian(a):
    var = 0
    var = var * a

def pembagian(a):
    var = 0
    var = var / a

while True : 
    nilai = int(input())
    var = input("lanjut? (y/n) : ")
    if var == "y" :
        pass
    else : 
        break


