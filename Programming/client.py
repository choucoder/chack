import zmq
from time import time
import numpy as np
import cv2
import pickle

ctx = zmq.Context()
client = ctx.socket(zmq.SUB)
client.connect("tcp://localhost:9000")
client.setsockopt_string(zmq.SUBSCRIBE, "")

frames = 0
startTime = time()

while True:
    width, height, data = client.recv_multipart()
    width, height = int(width), int(height)
    frame = np.frombuffer(data, dtype=np.uint8).reshape((width, height, 3))
    frames += 1
    elapsed = time() - startTime
    fps = round(frames / elapsed, 2)
    print(fps)