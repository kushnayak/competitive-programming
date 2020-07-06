//
//import java.io.BufferedReader;
//import java.io.FileReader;
//import java.util.*;
//
///*
//ID: kushnay1
//LANG: JAVA
//TASK: Milk Measurement
//*/
//public class MilkMeasurement {
//    public static void main(String[] args) throws Exception {
//        String in = "measurement.in";
//        String out = "test.out";
//
//        BufferedReader reader = new BufferedReader(new FileReader(in));
//        StringTokenizer tokens = new StringTokenizer(reader.readLine());
//        int six;                                                     ze = Integer.parseInt(tokens.nextToken());
//        ArrayList<Cow> logs = new ArrayList<>(size);
//        Cow newlog;
//        for (int i = 0; i < size; i++) {
//            tokens = new StringTokenizer(reader.readLine());
//            newlog = new Cow(Integer.parseInt(tokens.nextToken()),tokens.nextToken(),tokens.nextToken());
//            logs.add(newlog);
//
//        }
//        Collections.sort(logs);
//
//        HashMap<String, Integer> hashMap = new HashMap<>(3);
//        hashMap.put("Bessie",7);
//        hashMap.put("Elsie",7);
//        hashMap.put("Mildred",7);
//        //Bessie, Elsie, Mildred
//        HashMap<String,Boolean> prev = new HashMap<>(3);
//        HashMap<String,Boolean> current = new HashMap<>(3);
//        prev.put("Bessie",true);
//        prev.put("Elsie",true);
//        prev.put("Mildred",true);
//        current.put("Bessie",false);
//        current.put("Elsie",false);
//        current.put("Mildred",false);
//
//        for (Cow log: logs) {
//
//            hashMap.replace(log.cow,log.total(hashMap.get(log.cow)));
//            int max = Collections.max(hashMap.values());
//
//
//            }
//
//        }
//
//
//
//
//    }
//
//    public static class Cow implements Comparable<Cow> {
//        int day;
//        String cow;
//        String change;
//        public Cow(int day, String cow, String change) {
//            this.day = day;
//            this.cow = cow;
//            this.change = change;
//        }
//
//        public int total(int value) {
//            return (change.charAt(0) == '+') ? value + Integer.parseInt(change.substring(1,change.length())) : value - Integer.parseInt(change.substring(1,change.length()));
//
//        }
//
//        public int compareTo(Cow otherCow) {
//            return day - otherCow.day;
//        }
//    }
//
//
