#set( $in = '.in"' )
#set( $out = '.out"' )
#parse("File Header.java")
public class ${NAME} {

    public static void main(String[] args) throws IOException{
        InputReader reader = new InputReader("$in);
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("$out)));
        
        writer.close();
    }
    
    
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(String file) throws FileNotFoundException {
            reader = new BufferedReader(new FileReader(file));
            tokenizer = null;
        }
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
