declare function DuckDB(args: any): any;

export class DuckDBAPI {
    /// The loading promise
    protected moduleLoading: Promise<void> | null = null;
    /// The module
    protected module: any | null = null;

    constructor() {
    }

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
} 
