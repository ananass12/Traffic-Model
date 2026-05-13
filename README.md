# Traffic-Model

Тестовое задание - генерация сетевого трафика. Реализованы 2 модели сетевого трафика:

1. Равномерная. Новый пакет отправляется через фиксированный интервал после предыдущего, и у всех пакетов размер одинаковый.

2. Пуассоновская. Интервал между новым пакетом и предыдущим имеет распределение Пуассона, а размер пакета определяется экспоненциальным распределением.

## Сборка

```bash
mkdir build
cd build
cmake ../cpp
make
```

После сборки будет создан исполняемый файл:

```text
build/traffic_model
```

## Запуск

Равномерная (Uniform) модель:

```bash
./traffic_model ../examples/uniform.txt
```

Пуассоновская (Poisson) модель:

```bash
./traffic_model ../examples/poisson.txt
```

## Формат входных данных

```text
11.0
uniform: 1.0 512
```

```text
11.0
poisson: 2.0 0.01
```

## Формат выходных данных

```
time,size
0.0,512
1.0,512
2.0,512
```
где:

- time — время прихода пакета
- size — размер пакета

## Анализ

## Установка зависимостей

```bash
pip install -r requirements.txt
```
Запуск кода Python

```bash
python3 ../python/analyze.py ../output/output_poisson.csv
python3 ../python/analyze.py ../output/output_uniform.csv
```