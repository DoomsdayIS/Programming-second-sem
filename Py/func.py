import re
from collections import Counter

def password_check(password):
    if type(password) != str:
        return False
    length_check = True if (len(password) >= 7) else False
    contains_digit = any(map(str.isdigit, password))
    mixed_case = not password.islower() and not password.isupper()
    isalpha = re.match("^[a-zA-Z0-9]+$", password)
    no_repetitions = True if (len(password) == len(Counter(password))) else False
    if all([length_check,mixed_case,isalpha,no_repetitions,contains_digit]):
        return True
    else:
        return False
