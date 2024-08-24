#include "client.h"

int main(void)
{
	//---------------------------------------------------PARTE 2-------------------------------------------------------------/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	

	//log_info(logger, "Soy un log");


	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	

	if(config == NULL){
        abort();
    }

    if(config_has_property(config, "IP")){
        ip = config_get_string_value(config, "IP");
    }
    if(config_has_property(config, "PUERTO")){
        puerto = config_get_string_value(config, "PUERTO");
    }
    if(config_has_property(config, "CLAVE")){
        valor = config_get_string_value(config, "CLAVE");
    }

	log_info (logger,"IP: %s PUERTO: %s Valor: %s" ,ip,puerto,valor ); 

	// Loggeamos el valor de config

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	//readline("> ");

	//---------------------------------------------------PARTE 3-------------------------------------------------------------/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje (valor,conexion);

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	//---------------------------------------------------PARTE 5-------------------------------------------------------------/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;
	nuevo_logger = log_create("tp0.log", "logeo" ,1, LOG_LEVEL_INFO);
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;
	nuevo_config = config_create("cliente.config");
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");
	while(leido[0]!='\0'){
		log_info(logger, "%s", leido);
		free(leido);
		leido = readline("> ");
	}
	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	free(leido);

	// ¡No te olvides de liberar las lineas antes de regresar!
	return;
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
}
