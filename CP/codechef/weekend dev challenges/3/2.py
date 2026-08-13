import os

def list_applications():
# Write your code here
    print("--- Job Applications ---")
    app = ""
    if os.path.exists("applications.txt") :
        file = open("applications.txt", "r")
        app = file.read()
        if len(app) == 0:
            print("No applications found.")
            return
        print(app)
        file.close()
        return
    
    print("No applications found.")
    
    
        



def main():
    while True:
        print("========== Job Application Tracker ==========")
        print("1. Add Job Application")
        print("2. List All Applications")
        print("3. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            print("Add Function")
        elif choice == '2':
            list_applications()
        elif choice == '3':
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.\n")


if __name__ == "__main__":
    main()
