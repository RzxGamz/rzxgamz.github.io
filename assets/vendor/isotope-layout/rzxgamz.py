def pola_spiral(ukuran):
    """Membuat pola spiral persegi."""
    matrix = [[0 for _ in range(ukuran)] for _ in range(ukuran)]
    nilai = 1
    batas_atas, batas_bawah, batas_kiri, batas_kanan = 0, ukuran - 1, 0, ukuran - 1

    while batas_atas <= batas_bawah and batas_kiri <= batas_kanan:
        # Isi baris atas
        for i in range(batas_kiri, batas_kanan + 1):
            matrix[batas_atas][i] = nilai
            nilai += 1
        batas_atas += 1

        # Isi kolom kanan
        for i in range(batas_atas, batas_bawah + 1):
            matrix[i][batas_kanan] = nilai
            nilai += 1
        batas_kanan -= 1

        # Isi baris bawah
        if batas_atas <= batas_bawah:
            for i in range(batas_kanan, batas_kiri - 1, -1):
                matrix[batas_bawah][i] = nilai
                nilai += 1
            batas_bawah -= 1

        # Isi kolom kiri
        if batas_kiri <= batas_kanan:
            for i in range(batas_bawah, batas_atas - 1, -1):
                matrix[i][batas_kiri] = nilai
                nilai += 1
            batas_kiri += 1

    # Cetak matriks
    for baris in matrix:
        print(baris)

pola_spiral(5) # Anda dapat mengganti 5 dengan ukuran yang berbeda
