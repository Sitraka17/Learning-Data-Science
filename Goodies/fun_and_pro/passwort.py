import random
import string

def generate_strong_password(length=12):
    """
    Generate a strong random password.
    
    Parameters:
    length (int): The length of the password. Default is 12.
    
    Returns:
    str: A randomly generated strong password.
    """
    if length < 8:
        raise ValueError("Password length should be at least 8 characters for better security.")
    
    # Define the character pools
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase
    digits = string.digits
    special_characters = string.punctuation
    
    # Ensure the password includes at least one character from each pool
    all_characters = lowercase + uppercase + digits + special_characters
    
    # Pick one character from each pool to guarantee complexity
    password = [
        random.choice(lowercase),
        random.choice(uppercase),
        random.choice(digits),
        random.choice(special_characters)
    ]
    
    # Fill the remaining length with random characters from all pools
    password += random.choices(all_characters, k=length - 4)
    
    # Shuffle the password to ensure randomness
    random.shuffle(password)
    
    return ''.join(password)

# Example usage
if __name__ == "__main__":
    password_length = 16  # Adjust the length as needed
    print(f"Generated Password: {generate_strong_password(password_length)}")
