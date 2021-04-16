# Implementasi OOP - ICHIRO
Nama	:	Ryo Hilmi Ridho

NRP	:	5025201192

Departemen	:	Teknik Informatika

## Console TicTacToe
Program ini adalah sebuah game **TicTacToe** yang dapat dimainkan oleh 2 pemain

## Penjelasan Class
### Class TicTacToe 
Class **TicTacToe** memiliki beberapa atribut private, yaitu:
### board
Array 2D  yang berfungsi untuk menyimpan blok-blok permainan
### direction
Menyimpan arah gerak cursor
### isXTurn
Menandakan giliran
### currentX dan currentY
Menyimpan posisi cursor saat ini
### totalTurn
Menge-*track*  total blok yang sudah diisi

&nbsp;


Atribut public :
### isDone dan isDraw
Menandakan selesainya permainan
### isBlinking dan prevTime
Digunakan bersamaan untuk membuat efek kedip pada sebuah blok tiap satu detik
&nbsp;

Method public :
### printBoard
Mencetak papan permainan, beserta giliran saat ini
### moveCursor
Berpindah posisi di papan permainan
### changeDirection
Mendeteksi input keyboard untuk mengubah `direction` yang akan dipakai dalam method `changeDirection`
### blink
Menukar  `_` dengan `X` atau `O` setiap satu detik
### resetBlink
Mirip dengan method `blink`, namun mengabaikan jeda satu detik
### calculateWinner
Mengecek apakah permainan sudah dimenangkan oleh salah satu pemain atau seri
### turn
Mengisi sebuah blok, lalu memanggil `calculateWinner`
### resetGame
Mengembalikan permainan ke state awal
&nbsp;
----

### Class Player
Class Player digunakan untuk menyimpan data-data pemain

Atribut dan method dari class **Player**  :
### Player (Constructor)
### playerName 
Menyimpan nama pemain
### totalWin 
Menyipan total kemenangan pemain


