import os
import sys
import matplotlib.pyplot as plt
import numpy as np

def main():
    #режим роботи (обрана кнопка)
    mode = sys.argv[1].upper() if len(sys.argv) > 1 else "COMPARE"
    
    file_name = "plot_data.txt"
    if not os.path.exists(file_name):
        print(f"Помилк. Файл даних не знайдено!")
        return

    spectrum = []
    esprit_angles = []
    
    # аналіз даних парсинг файлу
    current_section = None
    with open(file_name, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            if line == "MUSIC_SPECTRUM":
                current_section = "MUSIC"
                continue
            elif line == "ESPRIT_ANGLES":
                current_section = "ESPRIT"
                continue
            
            try:
                val = float(line)
                if current_section == "MUSIC":
                    spectrum.append(val)
                elif current_section == "ESPRIT":
                    esprit_angles.append(val)
            except ValueError:
                continue

    plt.figure(figsize=(10, 6))
    
    # спектр мьюзік
    if mode in ["MUSIC", "COMPARE"] and spectrum:
        angles_music = np.linspace(-90, 90, len(spectrum))
        plt.plot(angles_music, spectrum, label='Спектр MUSIC', color='blue', linewidth=2)
        plt.ylabel('Потужність спектру', fontsize=12)

    #лінії значень еспріт
    if mode in ["ESPRIT", "COMPARE"] and esprit_angles:
        if mode == "ESPRIT":
            # якщо суто еспріт, то стовпці
            markerline, stemlines, baseline = plt.stem(esprit_angles, [1.0] * len(esprit_angles), 
                                                       linefmt='g--', markerfmt='go', basefmt=" ")
            plt.setp(markerline, 'markersize', 10, 'label', 'Оцінки ESPRIT')
            plt.setp(stemlines, 'linewidth', 2, 'color', 'green')
            plt.ylim([0, 1.2])
            plt.ylabel('Наявність джерела', fontsize=12)
            for angle in esprit_angles:
                plt.text(angle, 1.05, f'{angle:.2f}°', ha='center', va='bottom', fontweight='bold', color='darkgreen')
        else:
            # для порівняння накладання графіків
            for i, ang in enumerate(esprit_angles):
                label = 'Оцінка ESPRIT' if i == 0 else ""
                plt.axvline(x=ang, color='red', linestyle='--', linewidth=1.5, label=label)
                max_spec = max(spectrum) if spectrum else 1.0
                plt.text(ang, max_spec * 0.9, f' {ang:.1f}°', color='red', rotation=90, va='top', ha='left', fontweight='bold')

    plt.title(f'Результати аналізу DOA (Режим: {mode})', fontsize=14, fontweight='bold')
    plt.xlabel('Кут приходу', fontsize=12)
    plt.xlim([-90, 90])
    plt.xticks(np.arange(-90, 91, 15))
    plt.grid(True, linestyle=':', alpha=0.7)
    plt.legend(loc='upper right')
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()