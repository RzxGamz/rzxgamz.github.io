package main

import (
        "fmt"
        "math/rand"
        "time"
)

func main() {
        rand.Seed(time.Now().UnixNano())
        angkaRahasia := rand.Intn(100)
        percobaan := 0

        fmt.Println("Selamat datang di Permainan Tebak Angka!")
        fmt.Println("Saya telah memilih angka rahasia antara 0 dan 99.")
        fmt.Println("Bisakah kamu menebaknya?")

        for {
                percobaan++
                var tebakan int
                fmt.Print("Masukkan tebakanmu: ")
                _, err := fmt.Scanln(&tebakan)
                if err != nil {
                        fmt.Println("Masukan tidak valid. Silakan masukkan angka.")
                        continue
                }

                if tebakan < angkaRahasia {
                        fmt.Println("Terlalu rendah!")
                } else if tebakan > angkaRahasia {
                        fmt.Println("Terlalu tinggi!")
                } else {
                        fmt.Printf("Selamat! Kamu berhasil menebak angka rahasia dalam %d percobaan!\n", percobaan)
                        break
                }
        }
}
