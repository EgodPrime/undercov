import time
# from undercov import get_bb_cnt
import ctypes
import signal
import sys

_LIB = ctypes.CDLL('libundercov_info.so')
init_bitmap = _LIB.init_bitmap
close_bitmap = _LIB.close_bitmap
get_bb_cnt = _LIB.get_bb_cnt

class DMCCoverage:

    @staticmethod
    def init():
        init_bitmap()

    @staticmethod
    def close():
        close_bitmap()

    @staticmethod
    def get_now():
        return get_bb_cnt()

if __name__ == '__main__':
    def signal_hadnler(sig, frame):
        DMCCoverage.close()
        sys.exit(0)
    signal.signal(signal.SIGINT, signal_hadnler)

    DMCCoverage.init()
    while True:
        bb_cnt = DMCCoverage.get_now()
        print(f"Current bb cnt is {bb_cnt}")
        time.sleep(1)
