def factorial(n:int):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

x = int(input("Zadejte cislo, ktere chcete zfaktorializovat: "))

print(f"Faktorial cisla {x} je {factorial(x)}")

