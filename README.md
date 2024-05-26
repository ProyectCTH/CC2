# Patrones de diseño Estructural Proxy 

El patrón de diseño de Proxy es uno de los patrones estructurales más importantes en el ámbito de la programación orientada a objetos. Su propósito principal es proporcionar un objeto que controle el acceso a otro objeto, actuando como intermediario. Este patrón puede ser muy útil en diversas situaciones, como en la gestión de recursos costosos, el control de acceso y la mejora del rendimiento de una aplicación.

Tipos de Proxy
Existen varios tipos de proxy, cada uno con un propósito específico:

Proxy Virtual: Se utiliza para crear objetos costosos bajo demanda. Retrasa la creación y la carga de un objeto hasta que sea necesario.

Proxy de Protección: Controla el acceso a un objeto, proporcionando diferentes niveles de permisos a diferentes usuarios.

Proxy Remoto: Permite acceder a un objeto que reside en una ubicación remota, escondiendo los detalles de la comunicación remota.

Proxy de Caché: Proporciona almacenamiento temporal de resultados de operaciones costosas para mejorar el rendimiento.

Proxy Inteligente: Realiza tareas adicionales cuando se accede a un objeto, como el registro de accesos o la contabilidad.

Estructura
El patrón de diseño de Proxy típicamente incluye los siguientes componentes:

Subject (Sujeto): Una interfaz que define las operaciones que puede realizar el Proxy y el objeto real.
RealSubject (Sujeto Real): La clase que implementa la interfaz Subject y representa el objeto real al que se desea acceder.
Proxy: La clase que implementa la interfaz Subject y controla el acceso al RealSubject.
