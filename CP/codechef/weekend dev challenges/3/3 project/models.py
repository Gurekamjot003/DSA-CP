from django.db import models
from django.core.validators import MinValueValidator, MaxValueValidator

# TODO: Define a model class named 'Application' that inherits from models.Model
class Application(models.Model):
    # This list of choices is provided for you.
    POSITION_CHOICES = [
        ('Software Engineer', 'Software Engineer'),
        ('Product Manager', 'Product Manager'),
        ('Data Scientist', 'Data Scientist'),
        ('Junior Developer', 'Junior Developer'),
    ]

    # TODO: Define a CharField for the first name with max_length=100
    first_name = models.CharField(100)

    # TODO: Define a CharField for the last name with max_length=100
    last_name = models.CharField(100)

    # TODO: Define an EmailField that must be unique
    email = models.EmailField(unique= True)

    # TODO: Define a CharField for the phone number with max_length=15
    phone_number = models.CharField(15)

    # TODO: Define a CharField for the position, using the POSITION_CHOICES
    position = models.ChoiceField(POSITION_CHOICES)
    

    # TODO: Define a PositiveIntegerField for years of experience.
    # It should use validators to ensure the value is between 0 and 30.
    experience = models.IntegerField(validators = [MinValueValidator(0), MaxValueValidator(30)])

    # TODO: Define a DateField for the date the applicant is available
    date = models.DateField()
    
    # TODO: Implement the __str__ method to return a string in the format:
    # "{first_name} {last_name} - {position}"
    def __str__(self):
        # Your code here
        return self.first_name + self.last_name + " - " + self.position