def penjumlahan(a,b):
    return a+b
def pengurangan(a,b):
    return a-b
def perkalian(a,b):
    return a*b
def pembagian(a,b):
    return a/b


while True : 
    a = int(input("Masukkan angka pertama : "))
    op = input("Masukkan operasi hitung : ");
    #a = int(input("Masukkan angka pertama : "))
    b = int(input("Masukkan angka kedua : "))

    if op == "+":
        hasil = penjumlahan(a,b)
    elif op =="-":
        hasil = pengurangan(a,b)
    elif op == "x" or op == "*":
        hasil = perkalian(a,b)
    elif op == "/":
        hasil = pembagian(a,b)

    print(hasil)
    val = input("Lanjut? (y/n) : ")
    if val == "y" :
        pass
    elif val == "n" :
        break
    a = hasil #nilai pertama hanya ditambah di awal
