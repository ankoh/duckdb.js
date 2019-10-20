import React from 'react';
import { IAppContext, withAppContext } from './AppContext';

import './Demo.css';

interface IDemoProps {
    appContext: IAppContext,
}

class Demo extends React.Component<IDemoProps> {
    /// The terminal container
    protected termContainer: React.RefObject<HTMLDivElement>;
    /// The terminal input
    protected termInput: string;

    /// Constructor
    constructor(props: IDemoProps) {
        super(props);
        this.termContainer = React.createRef();
        this.termInput = "";
    }

    /// Render the demo
    public render() {
        return (
            <div className="demo">
                <div className="demo_header">
                    <div className="demo_header_logo">
                        <img src="duckdb-logo.png" alt="DuckDB" />
                    </div>
                    <div className="demo_header_name">
                        DuckDB
                    </div>
                    <div className="demo_header_poweredby">
                        powered by WASM
                    </div>
                </div>
                <div className="demo_term_borderbox">
                    <div ref={this.termContainer} className="demo_term_container">
                    </div>
                </div>
            </div>
        );
    }

    /// Evaluate the terminal input
    protected async evalTermInput(text: string) {
        /// XXX
        this.props.appContext.duckdb.query(text);
    }

    /// Run the terminal eval loop
    protected async runTermEvalLoop(text: string | null = null) {
        let term = this.props.appContext.terminal;

        // Handle terminal input
        if (text != null) {
            await this.evalTermInput(text)
        }

        // Schedule next read
        term.read("> ",  "   ",)
            .then(this.runTermEvalLoop.bind(this))
            .catch(function(text: string) {
                term.printLine("error: " + text);
            });       
    }

    public componentDidMount() {
        if (this.termContainer.current != null) {
            // Prepare the terminal
            let term = this.props.appContext.terminal;
            term.open(this.termContainer.current);
            term.fit();
            term.attach();
            term.focus();

            // Start the eval loop
            this.runTermEvalLoop();
        }
    }

    public componentWillUnmount() {
        let term = this.props.appContext.terminal;
        term.detach();
    }
}

export default withAppContext(Demo);
