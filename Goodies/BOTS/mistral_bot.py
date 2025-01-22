from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

def setup_driver():
    # Configure Chrome options
    chrome_options = Options()
    # Uncomment below lines if you need them
    # chrome_options.add_argument('--headless')  # Run in headless mode
    # chrome_options.add_argument('--no-sandbox')
    # chrome_options.add_argument('--disable-dev-shm-usage')

    # Initialize the Chrome driver with ChromeDriverManager
    driver = webdriver.Chrome(
        service=Service(ChromeDriverManager().install()),
        options=chrome_options
    )
    return driver

def search_google(driver, query):
    # Navigate to Google
    driver.get("https://www.google.com")

    # Wait until the search box is present and interactable
    search_box = WebDriverWait(driver, 10).until(
        EC.element_to_be_clickable((By.NAME, "q"))
    )

    # Enter the search query
    search_box.send_keys(query)

    # Submit the query
    search_box.send_keys(Keys.RETURN)

    # Wait for the results to load
    time.sleep(2)

    # Print the page title
    print(f"Page title: {driver.title}")

def main():
    try:
        # Set up the driver
        driver = setup_driver()

        # Set an implicit wait for all elements
        driver.implicitly_wait(10)

        # List of search queries
        queries = [
            "who is Sitraka FORLER",
            "How to be rich",
            "How to become a pro in IT"
        ]

        # Perform each search
        for query in queries:
            search_google(driver, query)
            time.sleep(2)  # Wait before the next search

    except Exception as e:
        print(f"An error occurred: {str(e)}")

    finally:
        # Always quit the driver
        if 'driver' in locals():
            driver.quit()

if __name__ == "__main__":
    main()
