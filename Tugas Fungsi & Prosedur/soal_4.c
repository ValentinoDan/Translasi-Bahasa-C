#include <stdio.h>
#include <stdbool.h> // import library agar bisa menggunakan boolean

// Definisi tipe data Tanggal
typedef struct {
    int DD; // Hari
    int MM; // Bulan
    int YY; // Tahun
} Tanggal;

// Fungsi untuk mengecek apakah tahun adalah kabisat
int IsKabisat(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Fungsi untuk mengecek apakah tanggal valid
bool IsTanggalValid(Tanggal T) {
    if (T.MM < 1 || T.MM > 12) return false; // Cek rentang bulan

    int HariDalamBulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Jika Februari pada tahun kabisat, ubah jumlah hari menjadi 29
    if (T.MM == 2 && IsKabisat(T.YY)) {
        HariDalamBulan[1] = 29;
    }

    return (T.DD >= 1 && T.DD <= HariDalamBulan[T.MM - 1]);
}

// Prosedur untuk membaca tanggal dari input pengguna
void BacaTanggal(Tanggal *T) {
    do {
        printf("Masukkan sebuah tanggal (<hari,tanggal,bulan>): ");
        scanf(" <%d,%d,%d>", &T->DD, &T->MM, &T->YY); // &T->DD berarti mengambil alamat dari T->DD, yang diperlukan untuk scanf("%d", &T->DD);

        if (!IsTanggalValid(*T)) {
            printf("Tanggal tidak valid, coba lagi.\n");
        }
    } while (!IsTanggalValid(*T));
}

// Fungsi untuk mengonversi bulan dalam angka ke nama bulan dalam bahasa Indonesia
const char* NamaBulan(int bulan) {
    const char *NamaBulanArray[] = {
        "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    };

    if (bulan < 1 || bulan > 12) {
        return "Bulan Tidak Valid";
    }
    return NamaBulanArray[bulan - 1]; // indeks mulai dari 0 sehingga harus dikurangi 1
}

// Prosedur untuk menampilkan tanggal
void TulisTanggal(Tanggal T) {
    printf("%d %s %d\n", T.DD, NamaBulan(T.MM), T.YY);
}

// Fungsi untuk mendapatkan hari berikutnya
Tanggal NextDay(Tanggal T) {
    int HariDalamBulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (T.MM == 2 && IsKabisat(T.YY)) {
        HariDalamBulan[1] = 29;
    }

    T.DD++; // Tambahkan 1 hari

    // Jika melebihi batas hari dalam bulan, ubah ke awal bulan berikutnya
    if (T.DD > HariDalamBulan[T.MM - 1]) {
        T.DD = 1;
        T.MM++;
        
        // Jika bulan melebihi Desember, ubah ke Januari tahun berikutnya
        if (T.MM > 12) {
            T.MM = 1;
            T.YY++;
        }
    }

    return T;
}

// Program utama
int main() {
    Tanggal T;

    printf("Program NextDay\n");
    BacaTanggal(&T);

    printf("Tanggal yang dimasukkan: ");
    TulisTanggal(T);

    T = NextDay(T);

    printf("Hari berikutnya adalah: ");
    TulisTanggal(T);

    return 0;
}
