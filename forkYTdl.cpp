#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

class Fork {
  private:
    pid_t pid;
    int segundos;
    char *url;
  
  public:
    // Constructor
    Fork (int seg,char *link) {
      segundos = seg;
      url = link;
      crear();
      ejecutarCodigo();
    }
    
    
    
    // Métodos.
    
    void validacion()
    {
    	if((url!=NULL) && (url[0]=='\0'))
    	{
    		std::cout << "Error. Url vacio";
		std::cout << std::endl;
		return;
    	}
    	else
    	{
    		std::cout << "Url: " << url;
    		std::cout << std::endl;
    	}
    }
    
    
    void crear() {
      // crea el proceso hijo.
      pid = fork();
    }
    
    void ejecutarCodigo () {
      //validacion del url.
      validacion();
      
      // valida la creación de proceso hijo.
      if (pid < 0) {
        std::cout << "No se pudo crear el proceso ...";
        std::cout << std::endl;
      
      } else if (pid == 0) {
        // Código del proceso hijo.
        std::cout << "ID Proceso hijo: " << getpid();
        std::cout << std::endl;
        std::cout << "Ejecuta código proceso hijo ...";
        std::cout << std::endl;
        
        
        execlp ("youtube-dl","--get-filename", "-o", "'%(title)s.%(ext)s'" , url, NULL);
        
        // Espera "segundos" para continuar (para pruebas).
        sleep(segundos);
      
      } else {
        // Código proceso padre.
        // Padre espera por el término del proceso hijo.
        wait (NULL);

        std::cout << "Termina código de proceso hijo ...";
        std::cout << std::endl;
        std::cout << "Continua con código proceso padre: " << getpid();
        std::cout << std::endl;
      }
    }
};

int main (int argc, char *argv[]) {
  // Instanciación.
  
  char *link = argv[1];
  
  Fork miFork(1,link);
  
  return 0;
}



