def is_valid_email(email):
    # Write your code here, Check whether email string contains '@' and '.'
    if '@' in email and '.' in email:
        return True
    return False
    

def is_valid_experience(exp):
    # Write your code here, Check whether the exp string contains numbers or alphabets. 
    if exp.isdigit() == False:
        return False
    exp = int(exp)
    if exp<0:
        return False
    return True
    # If it contains a number, convert it into an integer and check whether it is a non-negative number.
    

def add_application():

    # Write your code here
    print("\n--- Add Job Application ---")
    name = input("Enter Name: ")
    if len(name) == 0:
        return False
    email = input("Enter Email: ")
    if is_valid_email(email) == False:
        return False
    job_role = input("Enter Job Role: ")
    if len(job_role) == 0:
        return False
    exp = input("Enter your experience(in years): ")
    if is_valid_experience(exp) == False:
        return False
    
    file = open("applications.txt", "a") 
    file_text = ""
    file_text += "Name: " + name + "\n"
    file_text += "Email: " + email + "\n"
    file_text += "Role: " + job_role + "\n"
    file_text += "Experience: " + str(exp) + " years\n\n"
    file.write(file_text)
    file.close()

    return True


def main():
    while True:
        print("========== Job Application Tracker ==========")
        print("1. Add Job Application")
        print("2. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            add_application()
        elif choice == '2':
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.\n")


if __name__ == "__main__":
    main()
