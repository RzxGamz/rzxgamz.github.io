public class SeniTeks {

    public static void main(String[] args) {
        String teks = "WEBOT";
        int panjang = teks.length();

        for (int i = 0; i < panjang; i++) {
            for (int j = 0; j < panjang - i - 1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                System.out.print(teks.charAt(j) + " ");
            }
            System.out.println();
        }

        for (int i = panjang - 2; i >= 0; i--) {
            for (int j = 0; j < panjang - i - 1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                System.out.print(teks.charAt(j) + " ");
            }
            System.out.println();
        }
    }
}
