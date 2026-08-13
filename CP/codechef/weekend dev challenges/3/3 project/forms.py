# from django import forms
# from .models import Application
# # You may need to import other modules, like 're' for regular expressions
# import re

# # TODO: Define a form class named 'ApplicationForm' that inherits from forms.ModelForm
# class ApplicationForm(forms.ModelForm):
    
#     # TODO: Create the inner Meta class
#     class Meta:
#         # TODO: Specify the model this form is linked to
#         model = Application
        
#         # TODO: List all the fields from the model that should be in the form
#         fields = [
#             # ... list your fields here
#             'first_name',
#             'last_name',
#             'email',
#             'phone_number',
#             'position',
#             'experience',
#             'date'
#         ]

#         # TODO: Add a 'widgets' dictionary to customize the 'date_available' field.
#         # It should render as an HTML input with type="date".
#         widgets = {
#             'date': forms.DateInput({'type', 'date'})
#         }

#     # --- CUSTOM VALIDATION METHODS ---

#     # TODO: Implement the 'clean_phone_number' method for custom validation
#     def clean_phone_number(self):
#         """
#         Custom validation for the phone number field.
#         """
#         # TODO: Get the phone number from self.cleaned_data
#         phone = 
        
#         # TODO: Write a validation rule to ensure the phone number contains only
#         # numbers, spaces, parentheses '()', hyphens '-', and a plus sign '+'.
        
#         # TODO: If the validation fails, raise a forms.ValidationError with a helpful message.

#         # TODO: If validation passes, return the cleaned phone number
#         return phone

#     # TODO: Implement the 'clean' method for cross-field validation
#     def clean(self):
#         """
#         Custom validation for conditions between multiple fields.
#         """
#         # TODO: Get the cleaned data from the parent class's clean method
#         cleaned_data = 

#         # TODO: Get the 'position' and 'experience_years' values from cleaned_data
#         position = 
#         experience = 

#         # TODO: Check if both fields exist before comparing them
#         if position and experience is not None:
#             # TODO: Rule 1: If position is "Software Engineer", experience must be at least 3.
#             # If not, use self.add_error() to add an error to the 'experience_years' field.

#             # TODO: Rule 2: If position is "Junior Developer", experience cannot be more than 2.
#             # If it is, use self.add_error() to add an error to the 'experience_years' field.
            
#         # TODO: Return the full cleaned_data dictionary at the end
#         return cleaned_data