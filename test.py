from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
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

def main():
    try:
        # Set up the driver
        driver = setup_driver()
        
        # Set an implicit wait for all elements
        driver.implicitly_wait(10)
        
        # Navigate to a website (replace with your target URL)
        driver.get("https://www.linkedin.com/in/sitraka-matthieu-forler/")
        
        # Wait for page to load
        time.sleep(2)
        
        # Example of getting page title
        print(f"Page title: {driver.title}")
        
        # Example of finding elements (uncomment and modify as needed)
        # elements = driver.find_elements(By.TAG_NAME, "p")
        # for element in elements:
        #     print(element.text)
        
        # Example of explicit wait
        # element = WebDriverWait(driver, 10).until(
        #     EC.presence_of_element_located((By.ID, "some-id"))
        # )
        
    except Exception as e:
        print(f"An error occurred: {str(e)}")
    
    finally:
        # Always quit the driver
        if 'driver' in locals():
            driver.quit()

if __name__ == "__main__":
    main()
