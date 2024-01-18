import java.util.HashSet;

public class LongestSubstring{
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0, right = 0;

        HashSet<Character> uniqueChars = new HashSet<>();

        while (right < n) {
            if (!uniqueChars.contains(s.charAt(right))) {
                // Expand the window to the right
                uniqueChars.add(s.charAt(right));
                maxLength = Math.max(maxLength, right - left + 1);
                right++;
            } else {
                // Shrink the window from the left
                uniqueChars.remove(s.charAt(left));
                left++;
            }
        }
        return maxLength;
    }

    public static void main(String[] args) {
        LongestSubstring solution = new LongestSubstring();
        String input = "abcabcbb";
        int result = solution.lengthOfLongestSubstring(input);
        System.out.println("Output: " + result); // Output
    }
}
