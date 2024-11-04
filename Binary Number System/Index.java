public class Index {
    public static void main(String[] args) {
        String str = "himanshu";
        String reverse = "";

        for (int i = str.length() - 1; i >= 0; i--) {
            reverse += str.charAt(i);
        }

        str = reverse;

        System.out.println(str);
    }
}