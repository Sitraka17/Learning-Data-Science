import numpy as np
import cv2
my_img = np.zeros((400, 400, 3), dtype = "uint8")
# creating a rectangle
cv2.rectangle(my_img, (30, 30), (300, 200), (0, 20, 200), 10)
cv2.imshow('Window', my_img)
# allows us to see image
# until closed forcefully
cv2.waitKey(0)
cv2.destroyAllWindows()
