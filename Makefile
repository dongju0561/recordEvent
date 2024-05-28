CC = gcc
TARGET = detector
FILE = main.c event_detector.c event_logger.c

all : $(TARGET)

$(TARGET) : $(FILE)
	$(CC) -o $@ $^ -lpthread

clean :
	rm $(TARGET)