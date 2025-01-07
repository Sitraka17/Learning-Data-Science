from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# Set up the WebDriver
chrome_options = Options()
chrome_options.add_argument("--start-maximized")
service = Service('path/to/chromedriver')  # Update with the path to your WebDriver
driver = webdriver.Chrome(service=service, options=chrome_options)

# Function to log in to LinkedIn
def login_to_linkedin(email, password):
    driver.get("https://www.linkedin.com/login")
    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.ID, "username")))
    email_field = driver.find_element(By.ID, "username")
    password_field = driver.find_element(By.ID, "password")
    email_field.send_keys(email)
    password_field.send_keys(password)
    password_field.send_keys(Keys.RETURN)
    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.ID, "global-nav-typeahead")))

# Function to like posts in the feed
def like_posts():
    driver.get("https://www.linkedin.com/feed/")
    time.sleep(5)  # Wait for the feed to load
    SCROLL_PAUSE_TIME = 2

    # Get scroll height
    last_height = driver.execute_script("return document.body.scrollHeight")

    while True:
        # Scroll down to bottom
        driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")

        # Wait to load page
        time.sleep(SCROLL_PAUSE_TIME)

        # Calculate new scroll height and compare with last scroll height
        new_height = driver.execute_script("return document.body.scrollHeight")
        if new_height == last_height:
            break
        last_height = new_height

        # Like posts
        like_buttons = driver.find_elements(By.XPATH, "//button[contains(@aria-label, 'Like')]")
        for button in like_buttons:
            driver.execute_script("arguments[0].click();", button)
            time.sleep(1)  # Wait a bit to avoid being flagged as a bot

# Main function
def main():
    email = "your_email@example.com"
    password = "your_password"
    login_to_linkedin(email, password)
    like_posts()

if __name__ == "__main__":
    main()

