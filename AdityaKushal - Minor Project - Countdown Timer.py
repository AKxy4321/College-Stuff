import time
import threading

class CountdownTimer:
    def __init__(self, duration):
        self.duration = duration
        self.start_time = None
        self.paused = False
        self.remaining_time = duration
        self.timer_thread = None
        self.input_thread = None
        self.stopped = False

    def start(self):
        self.start_time = time.time()
        self.timer_thread = threading.Thread(target=self._run_timer)
        self.input_thread = threading.Thread(target=self._accept_input)
        self.timer_thread.start()
        self.input_thread.start()

    def _run_timer(self):
        while self.remaining_time > 0 and not self.stopped:
            if self.paused:
                time.sleep(1)
                continue

            elapsed_time = time.time() - self.start_time
            self.remaining_time = self.duration - elapsed_time

            minutes = int(self.remaining_time // 60)
            seconds = int(self.remaining_time % 60)

            print(f"  Time remaining: {minutes:02d}:{seconds:02d}")
            time.sleep(1)

    def _accept_input(self):
        print("p to pause, r to resume, s to stop, and t to reset\n")
        while self.timer_thread.is_alive():
            a = input("")
            if a == 'p':
                self.paused = True
            elif a == 'r':
                self.paused = False
            elif a == 's':
                self.stop()
                break
            elif a == 't':
                self.reset()
            else:
                continue

    def stop(self):
        print("Timer is stopped, pease run the code again to start the timer")
        self.stopped = True

    def reset(self):
        self.start_time = time.time()
        self.paused = False
        self.remaining_time = self.duration


n = int(input("Enter time: "))
timer = CountdownTimer(n)
timer.start()
