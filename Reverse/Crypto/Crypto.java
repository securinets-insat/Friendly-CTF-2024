import java.util.*;
import java.security.*;

public class Crypto {
    public static void main(String[] args) {
        System.out.println();
        System.out.println("== C R Y P T O ==");
        System.out.println("-- Author: jio --");
        System.out.println();
        System.out.println("Is this crypto or is it rev? You tell me!");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Give me the flag: ");
        String input = scanner.next();
        scanner.close();
        String part1 = "";
        String part2 = "";
        String part3 = "";
        String part4 = "";
        for(int i = 0; i < input.length(); i++) {
            if (i < 7) {
                part1 = part1 + input.charAt(i);
            } else if (i < 14) {
                part2 = part2 + input.charAt(i);
            } else if (i < 21) {
                part3 = part3 + input.charAt(i);
            } else {
                part4 = part4 + input.charAt(i);
            }
        }
        part1 = magic(part1);
        part2 = se7r(part2);
        part3 = abrakadabra(part3);
        part4 = tada(part4);
        String flag = "fe50b2772dba50891d6b66aa815010b13601031e312d2a7074302b523356PWwwdmUzfQ==";
        if((part1+part2+part3+part4).equals(flag)) {
            System.out.println("You got it! +1000 AURA");
        } else {
            System.out.println("Nope, that's not it. -100 aura");
        }
    }

    public static String magic(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] messageDigest = md.digest(input.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : messageDigest) {
                String hex = Integer.toHexString(0xFF & b);
                if (hex.length() == 1) {
                    hexString.append('0');
                }
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String se7r(String input) {
        String key = "Super_S3CR3T_Keyy";
        char[] keyChars = key.toCharArray();
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            output.append((char) (input.charAt(i) ^ keyChars[i % keyChars.length]));
        }
        return abrakadabra(output.toString());
    }

    public static String abrakadabra(String input) {
        StringBuilder hexString = new StringBuilder();
        for (char ch : input.toCharArray()) {
            String hex = Integer.toHexString(ch);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    }

    public static String tada(String input) {
        return Base64.getEncoder().encodeToString(input.getBytes());
    }
}
