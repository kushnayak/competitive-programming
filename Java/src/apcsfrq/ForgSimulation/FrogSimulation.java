import java.util.Random;

public class FrogSimulation {

    final private int goalDistance;
    final private int maxHops;

    public FrogSimulation(int goalDistance, int maxHops) {
        this.goalDistance = goalDistance;
        this.maxHops = maxHops;
    }
    private int hopDistance() {
        Random r = new Random();
        //low/high is range from where hop distance will be choose can be specified
        final int low = -10;
        final int high = 10;
        return r.nextInt(high - low + 1) + low;
    }
    public boolean simulate() {
        int pos = 0;
        boolean passed = false;
        for (int i=0; i<maxHops; i++) {
            int traveled = hopDistance();
            pos += traveled;
//            System.out.print(traveled + " ");
            if (pos < 0) {
                passed = false;
                break;
            }
            else if (pos >= goalDistance) {
                passed = true;
                break;
            }
        }
//        System.out.println();
//        System.out.println(passed);
        return passed;
    }
    public double runSimulations(int num){
        int passed = 0;
        for (int i=0; i<num; i++) {
            if (simulate()) passed++;
        }
        return 1.0*(passed)/(num);
    }

    public static void main(String[] args) {
        FrogSimulation fr = new FrogSimulation(24, 5);
        System.out.println(fr.runSimulations(100));

    }
}
