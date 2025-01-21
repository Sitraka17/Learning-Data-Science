# pip install pyautogui
import pyautogui
import time

def scroll_linkedin_page():
    # Give yourself some time to switch to the LinkedIn page in Chrome
    print("Switch to the LinkedIn page in Chrome within the next 5 seconds...")
    time.sleep(5)

    # Number of scrolls
    num_scrolls = 10

    for _ in range(num_scrolls):
        # Scroll down
        pyautogui.scroll(-100)  # Negative value to scroll down
        time.sleep(1)  # Wait for 1 second before the next scroll

    print("Scrolling completed.")

if __name__ == "__main__":
    scroll_linkedin_page()
