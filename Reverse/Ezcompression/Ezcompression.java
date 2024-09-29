import java.util.Scanner;

public class Ezcompression {

    public static boolean contains(String[] arr, String target) {
        for (String s : arr) {
            if (s != null && s.equals(target)) {
                return true;
            }
        }
        return false;
    }

    public static int getIndex(String[] arr, String target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != null && arr[i].equals(target)) {
                return i;
            }
        }
        return -1;
    }

    public static String printCapitalIndexes(int[] capitals) {
        String output = "";
        for (int i = 0; i < capitals.length; i++) {
            if(capitals[i] == 1)
            output += i;
        }
        if (output.length() == 0) {
            output = capitals.length + "";
        }
        return output;
    }

    public static void add(String[] arr, String target, int[] capitals) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == null) {
                arr[i] = target + printCapitalIndexes(capitals);
                return;
            }
        }
    }

    public static void add(String[] arr, String target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == null) {
                arr[i] = target;
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string to compress: ");
        String input = scanner.nextLine();
        scanner.close();
        String[] words = input.split("\\s+");
        String[] dictionary = new String[words.length];
        String[] outputCapitalized = new String[words.length];
        String output = "";
        for (String word : words) {
            int[] capitals = new int[word.length()];
            for (int i = 0; i < word.length(); i++) {
                if (Character.isUpperCase(word.charAt(i))) {
                    capitals[i] = 1;
                } else {
                    capitals[i] = 0;
                }
            }
            if (contains(dictionary, word)) {
                int index = getIndex(dictionary, word);
                output += index + " ";
            } else {
                add(outputCapitalized, word.toLowerCase(), capitals);
                add(dictionary, word);
                output += getIndex(dictionary, word);
            }
        }
        System.out.print(output);
        
        for (String word : outputCapitalized) {
            if (word != null) {
                System.out.print(word);
            }
        }
    }

}
