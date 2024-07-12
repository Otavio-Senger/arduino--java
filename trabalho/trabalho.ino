// Arrays com palavras em português e suas traduções em inglês
String palavrasPt[] = {"oi", "tudo bem", "gato", "prato", "pato"};
String palavrasEn[] = {"hello", "how are you", "cat", "plate", "duck"};
int numPalavras = 5;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  Serial.println("Digite uma palavra em português para traduzir para inglês:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Lê a mensagem até encontrar uma quebra de linha
    
    // Remove qualquer espaço em branco extra no início e no final da entrada
    input.trim();
    
    // Verifica se a palavra recebida está na lista de palavras em português
    for (int i = 0; i < numPalavras; i++) {
      if (input.equals(palavrasPt[i])) {
        // Envia a tradução correspondente pela porta serial
        Serial.print("Tradução em inglês de '");
        Serial.print(input);
        Serial.print("': ");
        Serial.println(palavrasEn[i]);
        break; // Sai do loop ao encontrar a palavra
      }
    }
    
    // Serial.println("Digite outra palavra em português para traduzir para inglês:");
  }
}


