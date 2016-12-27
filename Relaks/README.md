#Relaks
####Dynamic programming
##Zadanie: REL
Laboratorium z ASD, zadanie zaliczeniowe 1. Dostępna pamięć: 128 MB  
Tomek lubi chodzić po górach, ale jeszcze bardziej lubi odpoczywać podczas wędrówki – może wtedy obserwować
przyrodę i robić zdjęcia telefonem. Tomek woli chodzić po swojemu niż korzystać ze szlaków. Znalazł mapę
zbocza góry, na którą chce jutro wejść, i dla każdego miejsca ustalił liczbę punktów, które określają, jak bardzo
chciałby odpocząć w danym miejscu. Uzyskał w ten sposób tablicę liczb o m wierszach i n kolumnach. Tomek
zaczyna wędrówkę od odpoczynku w dowolnym polu w dolnym rzędzie; między każdymi dwoma polami odpoczynku
przesuwa się o 1 pole w górę i o co najwyżej 2 pola w lewo lub w prawo. Ostatni odpoczynek odbywa
się w dowolnym polu w górnym rzędzie, po czym Tomek wchodzi na szczyt, a następnie zaczyna schodzenie
w dół od dowolnego innego pola w górnym rzędzie. Schodzenie jest dla niego dużo mniej męczące, dlatego w
jednym ruchu przesuwa się o 2 lub 3 pola w dół i co najwyżej 1 w lewo lub w prawo. Ostatni odpoczynek
odbywa się w dowolnym polu w dolnym rzędzie, po czym Tomek kończy wędrówkę. Tomek zawsze tak planuje
swoją trasę, by nie odpoczywać dwa razy w tym samym polu, bo to nudne (a poza tym nie ma tam nowych
Pokemonów). Jaką trasę powinien wybrać, by zdobyć najwięcej punktów?
####Wejście
W pierwszym wierszu wejścia znajdują się dwie liczby całkowite m oraz n (3 ≤ m ≤ 500, 2 ≤ n ≤ 40),
oznaczające rozmiary tablicy Tomka.
Kolejne m wierszy zawiera opisy kolejnych rzędów tablicy: i-ty z nich zawiera n liczb całkowitych si,j (0 ≤
si,j ≤ 100 000) oznaczające liczbę punktów, które zdobędzie Tomek za odpoczynek na polu o współrzędnych
(i, j). Wiersze podawane są od najwyższego (najbliższego szczytu) do najniższego.
####Wyjście
W pierwszym i jedynym wierszu powinna znaleźć się dokładnie jedna liczba całkowita – największa liczba
punktów, którą może osiągnąć Tomek.
####Przykład
#####Dla danych wejściowych:
6 6  
9 1 1 1 6 1  
1 1 9 1 1 1  
1 1 1 8 1 1  
1 9 1 6 1 1  
1 1 1 9 1 1  
1 1 6 9 1 1  
######poprawnym wynikiem jest:
71  
Wyjaśnienie do przykładu: W optymalnej trasie Tomek będzie wchodził pod górę, odpoczywając po kolei
na wszystkich polach wartych po 8 i 9 punktów, a schodził, odpoczywając po kolei na wszystkich polach
wartych po 6 punktów (i żadnych innych). Zwróć uwagę, że Tomek nie mógł dwa razy odpoczywać na polu
wartym 8 punktów.