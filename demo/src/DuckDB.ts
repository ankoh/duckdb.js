declare function DuckDB(args: any): any;

export class DuckDBAPI {
    /// The loading promise
    protected moduleLoading: Promise<void> | null = null;
    /// The module
    protected module: any | null = null;

    /// Initialize the DuckDB api
    public init(): Promise<void> {
        this.moduleLoading = new Promise<void>(resolve => {
            this.module = DuckDB({
                print: function(text: any) {
                    console.log(text);
                },
                printErr: function(text: any) {
                    console.log(text);
                },
                onRuntimeInitialized: function() {
                    resolve();
                }
            });
        });
        return this.moduleLoading;
    }

    /// Wait until DuckDB is ready 
    public async waitUntilReady(): Promise<void> {
        if (this.moduleLoading != null) {
            return this.moduleLoading;
        } else {
            return Promise.resolve();
        }
    }

    /// Run a query
    public async query(text: string): Promise<void> {
        await this.waitUntilReady();

        // XXX Proof of concept
        // We don't want to reconnect every time
        let connection =  this.module.ccall('duckdb_web_connect', 'number', [], []);
        let result =  this.module.ccall('duckdb_web_query', 'number', ['number', 'string'], [connection, text]);
        this.module.ccall('duckdb_web_destroy_result', 'void', ['number'], [result]);
        this.module.ccall('duckdb_web_disconnect', 'void', [], []);

        return Promise.resolve();
    }
} 
