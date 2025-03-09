
fun main() {
    println("Selamat datang di dunia Kotlin!")

    // Menghasilkan deret Fibonacci
    val jumlahBilangan = 10
    var bilanganPertama = 0
    var bilanganKedua = 1

    print("Deret Fibonacci: $bilanganPertama, $bilanganKedua")

    for (i in 2 until jumlahBilangan) {
        val bilanganSelanjutnya = bilanganPertama + bilanganKedua
        print(", $bilanganSelanjutnya")

        bilanganPertama = bilanganKedua
        bilanganKedua = bilanganSelanjutnya
    }

    println()

    // Memeriksa apakah suatu bilangan prima
    val bilangan = 17
    val apakahPrima = cekApakahPrima(bilangan)

    if (apakahPrima) {
        println("$bilangan adalah bilangan prima.")
    } else {
        println("$bilangan bukan bilangan prima.")
    }
}

fun cekApakahPrima(bilangan: Int): Boolean {
    if (bilangan <= 1) {
        return false
    }

    for (i in 2 until bilangan) {
        if (bilangan % i == 0) {
            return false
        }
    }

    return true
}
