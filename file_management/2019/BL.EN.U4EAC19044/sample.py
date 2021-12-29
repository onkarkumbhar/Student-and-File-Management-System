import requests
from base64 import b64decode, b64encode
from tqdm import tqdm

# Bit flip code based on https://crypto.stackexchange.com/a/66086.
# we need to decode from base64 twice because the cookie was encoded twice.
def bit_flip(pos, bit, data):
    raw = b64decode(b64decode(data).decode())

    list1 = bytearray(raw)
    list1[pos] = list1[pos] ^ bit
    raw = bytes(list1)
    return b64encode(b64encode(raw)).decode()

cookie = "NDVLK3gyM3NPZTVpUmI0dlJYRGY0QVBvaXZzNFQ4UWtEeGpqN3UzdGRJN3k5TTZhczNWV1c4ZXZKK1pLYUxFVytpcnJ1YnlVeEpKbDBmbTBleHVCbit1Uzg5cXhIRkR2ZTM5ME1vK3p4YlVGUU1mS3lVWWFLMXFnL3VLUkh0VW0="
for position_idx in tqdm(range(10), desc="Bruteforcing Position"):
    # The 96 really should be 128 to test every bit, but 96 worked for me.
    for bit_idx in tqdm(range(96), desc="Bruteforcing Bit"):
        auth_cookie = bit_flip(position_idx, bit_idx, cookie)
        cookies = {'auth_name': auth_cookie}
        r = requests.get('http://mercury.picoctf.net:15614/', cookies=cookies)
        if "picoCTF{" in r.text:
            # The flag is between `<code>` and `</code>`
            print("Flag: " + r.text.split("<code>")[1].split("</code>")[0])
            break
