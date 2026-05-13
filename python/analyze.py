import os
import sys
import matplotlib.pyplot as plt
import pandas as pd

if len(sys.argv) != 2:
    print("Использование: python3 analyze.py <csv_file>")
    sys.exit(1)

csv_file = sys.argv[1]
base = os.path.basename(csv_file).lower()

if "uniform" in base:
    model_name = "Равномерная"
elif "poisson" in base:
    model_name = "Пуассоновская"
else:
    model_name = "Неизвестная"

df = pd.read_csv(csv_file)

times = df["time"]
sizes = df["size"]

delays = times.diff().dropna()

average_size = sizes.mean()
total_bits = sizes.sum() * 8

bitrate_denom = float(times.iloc[-1])
if bitrate_denom <= 0:
    bitrate_denom = 1e-9

bitrate = total_bits / bitrate_denom
average_delay = delays.mean()

print(f"Модель трафика: {model_name}")
print(f"Средний размер пакета: {average_size:.2f} bytes")
print(f"Средний битрейт: {bitrate:.2f} bit/s")
print(f"Средняя задержка: {average_delay:.4f} s")

plt.figure()
plt.subplot(2, 1, 1)
plt.hist(delays, bins=20)
plt.title("Гистограмма - задержка")
plt.xlabel("Задержка (с)")
plt.ylabel("Количество")
plt.grid()

plt.subplot(2, 1, 2)
plt.hist(sizes, bins=20)
plt.title("Гистограмма - размер пакетов")
plt.xlabel("Размер пакетов")
plt.ylabel("Количество")
plt.grid()

plt.tight_layout()
plt.show()