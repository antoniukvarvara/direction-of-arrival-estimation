import matplotlib.pyplot as plt
import numpy as np
import sys
import os

def plot_all():
    #читання даних з файлу
    script_dir = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(script_dir, "plot_data.txt")
    
    if not os.path.exists(file_path):
        print("Файл даних не знайдено")
        return

    with open(file_path, "r") as f:
        lines = f.readlines()
        
    #парсинг спектра
    spectrum = np.array([float(x) for x in lines[0].split()]) if len(lines) > 0 else None
    angles_music = np.linspace(-90, 90, len(spectrum)) if spectrum is not None else None
    
    #парсинг кутів
    esprit_angles = [float(x) for x in lines[1].split() if float(x) != 999.0] if len(lines) > 1 else []

    mode = sys.argv[1].upper() if len(sys.argv) > 1 else "COMPARE"
    
    plt.figure(figsize=(10, 6))
    
    #рисування спекрту мьюзік
    if (mode == "MUSIC" or mode == "COMPARE") and spectrum is not None:
        plt.plot(angles_music, spectrum, label='MUSIC Spectrum', color='blue')
    
    #рисування спектру еспріт
    if (mode == "ESPRIT" or mode == "COMPARE") and esprit_angles:
        for ang in esprit_angles:
            plt.axvline(x=ang, color='red', linestyle='--', label=f'ESPRIT: {ang:.1f}°')

    plt.title(f'Режим: {mode}')
    plt.xlabel('Кут (градуси)')
    plt.ylabel('Амплітуда / Потужність')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    plot_all()