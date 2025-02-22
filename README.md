# Controle de Matriz LED com Joystick - Embarcatech

## ![alt text](image.png) Apresentação do Projeto
- (https://youtu.be/PHpd8vkSmYo)  


## 🚀 Funcionalidades Principais
- **Controle direcional com Joystick**:
  - ↔️ Movimento Horizontal (Eixo X)
  - ↕️ Movimento Vertical (Eixo Y)
  - 🎮 4 direções reconhecidas: Cima, Baixo, Esquerda, Direita
- **Visualização em tempo real**:
  - Matriz LED 8x8 exibe setas direcionais em azul
  
- **Modos de operação**:
  - Feedback visual imediato dos movimentos
  - Reset automático para estado neutro

## 🛠️ Tecnologias Utilizadas
| Componente          | Especificações                |
|---------------------|-------------------------------|
| Microcontrolador    | Raspberry Pi Pico (RP2040)    |
| Matriz LED          | 8x8 com driver PIO            |
| Joystick            | Analógico (2 eixos)           |
| Protocolos          | I2C, PIO, ADC                 |

## 📦 Instalação
### Pré-requisitos
- [Visual Studio Code](https://code.visualstudio.com/)
- [Pico SDK](https://github.com/raspberrypi/pico-sdk)
- [CMake](https://cmake.org/) versão 3.12+

# Clone o repositório
git clone https://github.com/nilsonmazurchi/MatrizLedsJoystick-U7T_NM-Embarcatech.git
cd MatrizLedsJoystick-U7T_NM-Embarcatech

# Configure o ambiente
- mkdir build
- cd build
- cmake ..
- make -j4

## 🔌 Diagrama de Conexões
| Componente       | GPIO Pico | Tipo       |
|------------------|-----------|------------|
| Joystick (Eixo X)| GPIO26    | ADC0       |
| Joystick (Eixo Y)| GPIO27    | ADC1       |
| Matriz LED DATA  | GPIO07   | PIO0       |

## 🎮 Como Usar
### **Inicialização**:
- Todos LEDs apagados

### **Controles**:
- ➡️ Direita: LED → 
- ⬅️ Esquerda: LED ← 
- ⬆️ Cima: LED ↑ 
- ⬇️ Baixo: LED ↓ 

### **Modo Neutro**:
- Sem movimento por 2s → LEDs apagados


## ⚙️ Customização
```c
// config_matriz.h
#define BRILHO_LED 0.35    // Valores entre 0.0-1.0
#define THRESHOLD_LOW 1500  // Valor mínimo do ADC
#define THRESHOLD_HIGH 2500 // Valor máximo do ADC
#define TEMPO_DEBOUNCE 50   // ms para filtro de ruído
```

## ❗ Troubleshooting  
| Erro Comum               | Solução                      |  
|--------------------------|------------------------------|  
| LEDs não acendem         | Verifique conexão PIO        |  
| Leituras inconsistentes  | Calibre valores do ADC       |  
| Flickering na matriz     | Ajuste temporização no PIO   |  

## 📄 Licença  
**MIT License** - Consulte o arquivo [LICENSE](LICENSE) para detalhes.  

**Desenvolvido por** Nilson Mazurchi  
**Embarcatech** - 2025  
🚀 [Veja outros projetos](https://github.com/nilsonmazurchi?tab=repositories)
