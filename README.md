
# Algorytmy 1

Ten projekt zawiera implementację różnych zadań w języku C++. Kod obejmuje następujące funkcjonalności:

## 1. Tablica Dynamiczna

### Klasa `Tablica`

- Klasa `Tablica` reprezentuje dwuwymiarową tablicę dynamiczną.
- Pozwala na losowe wypełnienie tablicy, wyświetlenie jej zawartości i znalezienie maksymalnej wartości.

## 2. Zarządzanie Tablicą Stringów

- Funkcje `addStringElement`, `saveStringToFile`, `loadStringFromFile`, `saveStringToBinaryFile` i `loadStringFromBinaryFile` umożliwiają zarządzanie tablicą stringów.
- Pozwalają na dodawanie, zapisywanie i wczytywanie tablicy stringów do/z pliku tekstowego oraz zapisywanie i wczytywanie do/z pliku binarnego.

## 3. Funkcje Matematyczne

- Funkcje `potega` i `silnia` obliczają odpowiednio potęgę i silnię liczby.
- Funkcja `jestPal` sprawdza, czy dany tekst jest palindromem.

## 4. Permutacje Palindromów

- Funkcja `permutuj` generuje wszystkie permutacje danego tekstu i sprawdza, czy są palindromami.
- Funkcje `usunDup` i `wyswpal` służą do usuwania duplikatów palindromów i wyświetlania wyników.

## 5. Struktury Danych

- Zaimplementowane są dwie struktury danych: lista jednokierunkowa (`ListaJ`) i kolejka (`Kolejka`).
- Struktura `ListF` zawiera funkcje do zarządzania listą jednokierunkową, takie jak dodawanie, usuwanie elementów oraz wyświetlanie zawartości.
- Struktura `Kolejka` reprezentuje kolejkę i posiada funkcje dodawania, usuwania elementów oraz wyświetlania zawartości.

## Jak Uruchomić
1. Skompiluj kod za pomocą kompilatora C++.
2. Uruchom program, który demonstruje działanie każdej z implementacji.

# Algorytmy 2 - Sortowanie Danych Filmowych

Ten kod C++ zawiera trzy algorytmy sortowania dla wektora obiektów `MovieData` opartych na ich zmiennej `averageRating`. Trzy algorytmy sortowania zawarte w kodzie to:

1. Quick Sort (Szybkie Sortowanie)
2. Merge Sort (Sortowanie Przez Scalanie)
3. Bucket Sort (Sortowanie Kubkowe)

## Quick Sort (Szybkie Sortowanie)

Funkcja `quickSort` implementuje algorytm Szybkiego Sortowania. Wybiera element osiowy (tzw. "pivot") i dzieli wektor na dwie podtablice: jedną zawierającą elementy mniejsze od pivota, a drugą zawierającą elementy większe od pivota. Następnie rekurencyjnie sortuje te podtablice.

## Merge Sort (Sortowanie Przez Scalanie)

Funkcja `mergeSort` implementuje algorytm Sortowania Przez Scalanie. Dzieli wektor na dwie połowy, rekurencyjnie sortuje je, a następnie scala posortowane połowy, aby uzyskać ostatecznie posortowany wektor.

## Bucket Sort (Sortowanie Kubkowe)

Funkcja `bucketSort` implementuje algorytm Sortowania Kubkowego. Określa ona minimalną i maksymalną wartość zmiennej `averageRating` w wektorze, tworzy kubełki dla każdej różnej wartości oceny i rozdziela obiekty `MovieData` do tych kubełków. Następnie scala te kubełki, aby uzyskać posortowany wektor.





