#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int level;
    int a, b, c, jawaban, benar;
    int skor = 0;
    time_t start, end;

    srand(time(NULL));

    printf("====== GAME HITUNG CEPAT KOMBINASI ======\n");
    printf("Pilih level:\n");
    printf("1. Mudah\n");
    printf("2. Sedang\n");
    printf("3. Sulit\n");
    printf("Masukkan level: ");
    scanf("%d", &level);

    printf("\nGame dimulai! Ada 10 soal kombinasi.\n\n");

    for (int i = 1; i <= 10; i++) {
        int jenisSoal = rand() % 5;
        // 0 = √a x b
        // 1 = a x √b
        // 2 = (a + b) x √c
        // 3 = a^2 + √b
        // 4 = (√a + √b) x c

        // Generate angka berdasarkan level
        if (level == 1) {
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
            c = rand() % 10 + 1;
        }
        else if (level == 2) {
            a = rand() % 20 + 1;
            b = rand() % 20 + 1;
            c = rand() % 20 + 1;
        }
        else {
            a = rand() % 50 + 1;
            b = rand() % 50 + 1;
            c = rand() % 50 + 1;
        }

        // Pastikan akar memiliki hasil bulat
        int akarA = (rand() % 10 + 2);
        int akarB = (rand() % 10 + 2);
        int akarC = (rand() % 10 + 2);

        int kuadratA = akarA * akarA;
        int kuadratB = akarB * akarB;
        int kuadratC = akarC * akarC;

        printf("===== Soal %d =====\n", i);

        // ============================================
        //               BENTUK SOAL
        // ============================================
        if (jenisSoal == 0) {
            // √a × b
            printf("Hitung: √%d × %d = ?\n", kuadratA, b);
            benar = akarA * b;
        }
        else if (jenisSoal == 1) {
            // a × √b
            printf("Hitung: %d × √%d = ?\n", a, kuadratB);
            benar = a * akarB;
        }
        else if (jenisSoal == 2) {
            // (a + b) × √c
            printf("Hitung: (%d + %d) × √%d = ?\n", a, b, kuadratC);
            benar = (a + b) * akarC;
        }
        else if (jenisSoal == 3) {
            // a^2 + √b
            printf("Hitung: (%d^2) + √%d = ?\n", a, kuadratB);
            benar = (a * a) + akarB;
        }
        else if (jenisSoal == 4) {
            // (√a + √b) × c
            printf("Hitung: (√%d + √%d) × %d = ?\n", kuadratA, kuadratB, c);
            benar = (akarA + akarB) * c;
        }

        // ======================== TIMER 5 DETIK ========================
        printf("Jawaban kamu (punya waktu 5 detik): ");
        time(&start);
        scanf("%d", &jawaban);
        time(&end);

        double waktu = difftime(end, start);

        if (waktu > 5) {
            printf("⚠️ Terlambat! Kamu melewati batas waktu.\n");
        }
        else if (jawaban == benar) {
            printf("Benar! Good job!\n");
            skor++;
        }
        else {
            printf("Salah! Jawaban yang benar adalah: %d\n", benar);
        }

        printf("\n");
    }

    printf("====== Permainan Selesai! ======\n");
    printf("Skor akhir kamu dari 10 soal: %d\n", skor);

    return 0;
}
