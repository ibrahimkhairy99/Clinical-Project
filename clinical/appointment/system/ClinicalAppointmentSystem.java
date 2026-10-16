import java.util.Scanner;

public class ClinicalAppointmentSystem {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n=========================================");
            System.out.println("   ONLINE CLINIC APPOINTMENT SYSTEM      ");
            System.out.println("   Developer: Ibrahim Mohamed (1202540507) ");
            System.out.println("=========================================");
            System.out.println("1. Patient Portal (Book Appointment)");
            System.out.println("2. Doctor Portal (View Schedule)");
            System.out.println("3. Admin Portal (View Summary)");
            System.out.println("4. Exit");
            System.out.print("Enter your choice (1-4): ");

            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("\n--- Patient Portal ---");
                    System.out.println("Appointment Booked Successfully!");
                    break;
                case 2:
                    System.out.println("\n--- Doctor Schedule ---");
                    System.out.println("APT101: Mohamed Ali - 5:00 PM - Confirmed");
                    break;
                case 3:
                    System.out.println("\n--- Admin Overview ---");
                    System.out.println("Total Revenue: 900 EGP");
                    break;
                case 4:
                    System.out.println("Exiting... Thank you!");
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        } while (choice != 4);

        scanner.close();
    }
}