// Arrays com palavras em português e suas traduções em inglês
String palavrasPt[] = {"oi", "tudo bem?", "gato", "prato", "pato"};
String palavrasEn[] = {"hello", "how are you", "cat", "plate", "duck"};
int numPalavras = 5;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available()) {
    // Lê a mensagem até encontrar uma quebra de linha
    String input = Serial.readStringUntil('\n');
    
    
    // Inicializa uma variável para verificar se a palavra foi encontrada
    bool encontrada = false;
    
    // Verifica se a palavra recebida está na lista de palavras em português
    for (int i = 0; i < numPalavras; i++) {
      if (input.equals(palavrasPt[i])) {
        // Envia a tradução correspondente pela porta serial
        Serial.print("Tradução em inglês de '");
        Serial.print(input);
        Serial.print("': ");
        Serial.println(palavrasEn[i]);
        
        // Define a variável como verdadeira para indicar que a palavra foi encontrada
        encontrada = true;
        break; // Sai do loop ao encontrar a palavra
      }
    }
    
    // Se a palavra não foi encontrada, envia uma mensagem de erro
    if (!encontrada) {
      Serial.print("A palavra '");
      Serial.print(input);
      Serial.println("' não foi encontrada no dicionário.");
    }
  }
}
